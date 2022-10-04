#!/bin/bash

args=""

if [ $# -gt 1 ]; then
	args=$2
fi
if ! eval "../../app.exe ${args}<${1}>./out.txt"; then
	exit 1
fi
exit 0
