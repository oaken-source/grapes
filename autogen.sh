#!/bin/sh

mkdir -p m4
autoreconf --install || ( echo "autoreconf failed." >&2 && exit 1 )
