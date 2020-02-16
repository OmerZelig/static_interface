#!/bin/bash

#
# Author: Omer Zelig
#

set -e

if [ "${1}" == "help" ]  ||
   [ "${1}" == "-help" ] ||
   [ "${1}" == "h" ]     ||
   [ "${1}" == "-h" ]    
then
  echo "usage:"
  echo "./configre c=[COMPILER] p=[INSTALL_PREFIX] "
  echo "INSTALL_PREFIX where to install the lib, default is system default"
  echo "COMPILER is {gcc, clang}, default is gcc"
  exit
fi

COMPILER=gcc

IFS=', ' read -r -a array <<< "${@}"
for item in "${array[@]}"
do
  case "${item::2}" in
    p=)
      INSTALL_PATH="${item:2}" # remove the first two letters
      ;;
    c=)
      COMPILER="${item:2}" # remove the first two letters
      ;;
   esac
done


ROOT_PATH="${PWD}"

if [ "${COMPILER}" == "clang" ]
then
  echo "using clang !"
  export CC=/usr/bin/clang
  export CXX=/usr/bin/clang++
fi

cd ${ROOT_PATH}/_build


if [ -z "${INSTALL_PATH}" ]
then
      # Empty, no install path
      cmake ..
else
      cmake -DCMAKE_INSTALL_PREFIX:PATH=${INSTALL_PATH} ..
fi

cd -
