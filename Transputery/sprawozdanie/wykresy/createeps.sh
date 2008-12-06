#!/bin/bash
for i in $(ls *.png); do
	convert $i `basename $i .png`.eps	
done
