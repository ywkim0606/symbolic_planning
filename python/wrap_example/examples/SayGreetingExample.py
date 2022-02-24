"""
GTSAM Copyright 2010-2019, Georgia Tech Research Corporation,
Atlanta, Georgia 30332-0415
All Rights Reserved

See LICENSE for the license information

Example comparing DoglegOptimizer with Levenberg-Marquardt.
Author: Frank Dellaert
"""
# pylint: disable=no-member, invalid-name

import math
import argparse

from wrap_example import Greeting

def run(args):
    g = Greeting()
    if args.goodbye:
        g.sayGoodbye()
    else:
        g.sayHello()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Compare Dogleg and LM success rates")
    parser.add_argument("-b", "--goodbye",
                        help="Say goodbye instead of hello.")
    args = parser.parse_args()
    run(args)
