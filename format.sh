#!/usr/bin/env bash
ls | grep -E '\.c|\.h' | xargs -i clang-format -i {} --style="{BasedOnStyle: llvm, IndentWidth: 4}"
