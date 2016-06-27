#!/bin/bash

python -m SimpleHTTPServer 8888 &
pid=$!
read l
kill -9 $pid
exit 0


