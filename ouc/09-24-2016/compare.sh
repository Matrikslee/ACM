#!/bin/sh
./ra > input
./ta < input > output
./std < input > stdo
diff output stdo
