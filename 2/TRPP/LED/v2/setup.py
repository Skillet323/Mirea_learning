from setuptools import setup, find_packages
from sphinx.setup_command import BuildDoc

setup(
    name="led_control",
    version="0.1.0",
    packages=find_packages(),
    include_package_data=True,
    install_requires=[
        "Flask>=2.0",
        "requests>=2.25",
    ],
    entry_points={
        'console_scripts': [
            'led-control=app:main'
        ]
    },
    setup_requires=["sphinx", "sphinx-rtd-theme"],
    cmdclass={
        'build_sphinx': BuildDoc
    },
    command_options={
        'build_sphinx': {
            'project': ('setup.py', 'LED Control'),
            'version': ('setup.py', '0.1.0'),
            'source_dir': ('setup.py', 'docs')
        }
    }
)