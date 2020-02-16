#!/bin/bash

set -e

ROOT_PATH="${PWD}"

cd ${ROOT_PATH}/_build
make -j8
cd -
