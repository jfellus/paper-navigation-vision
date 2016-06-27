#!/bin/sh

i=0
for l in `ls data/images`; do
	mv -f "data/images/$l" data/images/$(printf "%08d" $i).jpg 2>/dev/null
	i=$(( $i + 1 ))
done

echo $i > data/N
echo "Processed $i images"
