#!/usr/bin/env bash
\ls | grep -E '\.c|\.h' | xargs clang-format -i {} --style=Microsoft
