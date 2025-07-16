from setuptools import Extension, setup

setup(
    include_package_data=True,
    package_data={'rpeasings': ['*.h']},
    ext_modules=[
        Extension('rpeasings', ['src_c/rpeasings.c'], include_dirs=['src/rpeasings/include'])
    ]
)
