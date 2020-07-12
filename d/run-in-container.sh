#!/bin/sh
docker run --rm -it -v $(pwd):/src dlang2/dmd-ubuntu dmd -run /src/hello.d
