
from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

ext_modules=[
    Extension("getDFCF",
              sources=["getDFCF.pyx"],
    )
]

setup(
  name = "read DFCF data",
  ext_modules = cythonize(ext_modules)
)


