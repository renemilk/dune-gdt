#!/bin/bash

if [[ $TRAVIS_JOB_NUMBER == *.1 ]] ; then
    git config --global hooks.clangformat ${CLANG_FORMAT}
    CHECK_DIR=${SUPERDIR}/${MY_MODULE}
    PYTHONPATH=${SUPERDIR}/scripts/python/ python3 -c "import travis_report as tp; tp.clang_format_status(\"${CHECK_DIR}\")"
    ${SRC_DCTRL} ${BLD} --only=${MY_MODULE} configure
    ${SRC_DCTRL} ${BLD} --only=${MY_MODULE} make doc
    ${SUPERDIR}/.travis/init_sshkey.sh ${encrypted_95fb78800815_key} ${encrypted_95fb78800815_iv} keys/dune-community/dune-community.github.io
    ${SUPERDIR}/.travis/deploy_docs.sh ${MY_MODULE} "${DUNE_BUILD_DIR}"
fi
