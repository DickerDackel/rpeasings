#!/bin/env python3

import pygame
import pygame._sdl2 as sdl2

from pgcooldown import Cooldown, lerp
from rpeasings import easings

TITLE = 'pygame minimal template'
SCREEN = pygame.Rect(0, 0, 1024, 768)
FPS = 60
DT_MAX = 3 / FPS
CELL_SIZE = 128
ROWS = 4
COLUMNS = 8

clock = pygame.time.Clock()
window = pygame.Window(title=TITLE, fullscreen_desktop=True)
renderer = sdl2.Renderer(window)
renderer.logical_size = (1024, 768)

pygame.font.init()
ZE_FONT = pygame.font.Font(None, size=24)


class EaseBox:
    def __init__(self, renderer, rect, easing):
        self.renderer = renderer
        self.rect = rect.copy()
        self.easing = easing

        self.prev_t = 0
        self.trail = []

        label = ZE_FONT.render(easing.__name__, True, 'white')
        self.label = sdl2.Texture.from_surface(renderer, label)
        self.lab_rect = label.get_rect(midtop=(rect.centerx, rect.bottom + 5))

    def draw(self, t):
        xoffset = lerp(0, self.rect.width, t)
        yoffset = lerp(0, self.rect.height, self.easing(t))

        renderer.draw_color = 'black'
        renderer.fill_rect(self.rect)
        renderer.draw_color = 'white'
        renderer.draw_rect(self.rect)

        if t < self.prev_t:
            self.trail = []
        self.prev_t = t

        rect = pygame.Rect(0, 0, 2, 2)
        rect.center = (self.rect.left + xoffset, self.rect.bottom - yoffset)
        self.trail.append(rect)

        renderer.draw_color = 'red'
        for r in self.trail[:-1]:
            renderer.fill_rect(r)

        renderer.draw_color = 'yellow'
        renderer.fill_rect(self.trail[-1].inflate((3, 3)))

        renderer.draw_color = 'white'
        self.label.draw(dstrect=self.lab_rect)


boxes = []
ease = iter(easings.values())

def map_x(x):
    return ((SCREEN.width - COLUMNS * CELL_SIZE) // 2
            + CELL_SIZE // 2
            + x * CELL_SIZE)

def map_y(y):
    return ((SCREEN.height - ROWS * CELL_SIZE) // 2
            + CELL_SIZE // 2
            + y * CELL_SIZE)

for y in range(4):
    ypos = map_y(y)
    for x in range(8):
        xpos = map_x(x)

        box = EaseBox(renderer,
                      pygame.Rect(0, 0, CELL_SIZE * 0.6, CELL_SIZE * 0.6).move_to(center=(xpos, ypos)),
                      next(ease))
        boxes.append(box)

heartbeat = Cooldown(3)
wait = Cooldown(2)
running = True
while running:
    dt = min(clock.tick(FPS) / 1000.0, DT_MAX)

    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            running = False
        elif e.type == pygame.KEYDOWN:
            if e.key == pygame.K_ESCAPE:
                running = False

    if heartbeat.cold():
        heartbeat.reset()

    renderer.draw_color = 'black'
    renderer.clear()

    ease = iter(easings.values())
    for box in boxes:
        box.draw(heartbeat.normalized)

    renderer.present()

    window.title = f'{TITLE} - time={pygame.time.get_ticks()/1000:.2f}  fps={clock.get_fps():.2f}'
