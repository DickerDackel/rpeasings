from setuptools import Extension, setup

setup(
    include_package_data=True,
    package_data={'rpeasings': ['*.h', "py.typed"]},
    ext_package = 'rpeasings',
    ext_modules=[
        Extension('_rpeasings', ['src_c/rpeasings.c'], include_dirs=['src/rpeasings/include'])
    ]
)
