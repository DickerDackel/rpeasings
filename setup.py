from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension('rpeasings', ['src_c/rpeasings.c'])
    ]
)
