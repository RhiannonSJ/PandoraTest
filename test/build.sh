#!/bin/bash

export FHICL_DIR=/sbnd/app/users/rsjones/LArSoft_v06_56_00/LArSoft-v06_56_00/srcs/pandoratesting/pandoratesting
cd $MRB_BUILDDIR
mrbsetenv
mrb i -j4
mrbslp
cd -
export FHICL_FILE_PATH=${FHICL_DIR}:${FHICL_FILE_PATH}
