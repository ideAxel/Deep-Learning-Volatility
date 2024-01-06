from setuptools import setup, Extension
import pybind11

setup(
    name='CppNeuralNet',
    version='1.0',
    ext_modules=[
        Extension(
            'cppNeuralNet',
            ['cppNeuralNet.cpp'],
            include_dirs=[
                pybind11.get_include(), 
                'C:/Users/AD/Desktop/testcpp/eigen/eigen-3.4.0'
                           
                           ],
            language='c++'
        ),
    ],
)


