"""
GTSAM Copyright 2010-2019, Georgia Tech Research Corporation,
Atlanta, Georgia 30332-0415
All Rights Reserved

See LICENSE for the license information

Basic tests for the example.

Author: Frank Dellaert & Duy Nguyen Ta & Varun Agrawal
"""
import unittest

import wrap_example


class TestWrapExample:
    """Simple test class."""
    def test_Hello(self):
        """Should print `Hello from C++!`"""
        g = wrap_example.Greeting()
        g.sayHello()

    def test_Goodbye(self):
        """Should print `Goodbye, robot`"""
        g = wrap_example.Greeting()
        g.sayGoodbye()


if __name__ == "__main__":
    unittest.main()
