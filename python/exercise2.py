####################################################################################################################
#   ______   __                            __              __
#  /      \ /  |                          /  |            /  |
# /$$$$$$  |$$ |____    _______   ______  $$ | __    __  _$$ |_     ______    ______
# $$ |__$$ |$$      \  /       | /      \ $$ |/  |  /  |/ $$   |   /      \  /      \
# $$    $$ |$$$$$$$  |/$$$$$$$/ /$$$$$$  |$$ |$$ |  $$ |$$$$$$/   /$$$$$$  |/$$$$$$  |
# $$$$$$$$ |$$ |  $$ |$$      \ $$ |  $$ |$$ |$$ |  $$ |  $$ | __ $$    $$ |$$ |  $$/
# $$ |  $$ |$$ |__$$ | $$$$$$  |$$ \__$$ |$$ |$$ \__$$ |  $$ |/  |$$$$$$$$/ $$ |
# $$ |  $$ |$$    $$/ /     $$/ $$    $$/ $$ |$$    $$/   $$  $$/ $$       |$$ |
# $$/   $$/ $$$$$$$/  $$$$$$$/   $$$$$$/  $$/  $$$$$$/     $$$$/   $$$$$$$/ $$/
#
# Create a script able to list files and directories contained in the same directory as the script executable.
# This result must be independent on the folder the script is executed from.
#
# To better explain let's assume the following structure:
#
#   ├── README.md
#   ├── bash
#   │   ├── exercise1.sh
#   │   └── exercise2.sh
#   ├── c++
#   │   ├── exercise1.cpp
#   │   └── exercise2.cpp
#   └── python
#       ├── exercise1.py
#       └── exercise2.py
#
# This script is "exercise2.py". It should list itself and "exercise1.py" (same as "ls"), no matter the workdir.
#
# E.g. one should run the script as:
#  * ./open-forbc-candidate-test/python/exercise2.py when at open-forbc-candidate-test
#  * ./../python/exercise2.py when at open-forbc-candidate-test/c++
#  * <abs path to this repo>/open-forbc-candidate-test/python/exercise2.py for anywhere
#
# And always get the same result.
#
####################################################################################################################

import os

# files = os.listdir(os.curdir)
destdir = os.path.dirname(os.path.abspath(__file__))
files = [f for f in os.listdir(destdir) if os.path.isfile(os.path.join(destdir, f)) or os.path.isdir(os.path.join(destdir, f))]
for file in files:
    print(file)
