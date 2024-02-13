from setuptools import find_packages
from setuptools import setup

setup(
    name='opencv',
    version='0.0.0',
    packages=find_packages(
        include=('opencv', 'opencv.*')),
)
