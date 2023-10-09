#!/bin/bash

docker build ~/CURSUS/CPPPiscine -t pruebas
docker run -it --rm -v=$PWD:/code pruebas