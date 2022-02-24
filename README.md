# wrap-project-python

Project template illustrating python wrapping with borglab/wrap, **no** GTSAM.

This file will be included as the python package description :)

## PREREQUISITES

- Python 3.6+ is required.
- Install the `wrap` repo located [here](https://github.com/borglab/wrap).

## INSTALL

- Clone this repository with all submodules by `git clone https://github.com/borglab/wrap-project-python.git`
- In the project directory, create a `build` directory and `cd` into it.
- Run `cmake ..` (with optional prefix of your choice)
- Run `make`, and the wrapped module will built into build/python.
- Run `make install`, which will install the C++ library (only) to the cmake prefix.
- Run `make python-install`, which will run `python build/setup.py install` in your current environment.

## TEST

After install, you can test whether everything works using, say, a quick ipython session:

```
> ipython
Python 3.7.7 (default, Mar 26 2020, 10:32:53) 
Type 'copyright', 'credits' or 'license' for more information
IPython 7.13.0 -- An enhanced Interactive Python. Type '?' for help.

In [1]: import wrap_example                                                                                                                               

In [2]: g = wrap_example.Greeting()                                                                                                                       

In [3]: g.sayHello()                                                                                                                                     
Hello from C++!

In [4]: g.sayGoodbye()                                                                                                                                   
Goodbye, robot
```
