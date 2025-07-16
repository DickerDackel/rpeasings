from setuptools import Extension, setup

setup(
    include_package_data=True,
    ext_modules=[
        Extension('rpeasings', ['src_c/rpeasings.c'], include_dirs=['include'])
    ]
)
