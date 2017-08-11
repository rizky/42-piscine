#!/bin/sh

var=$(ifconfig | grep "inet " | cut -d' ' -f2)
if [ ! -z "$var" ]
then
	echo $var | tr ' ' '\n'
else
	echo "Je suis perdu!\n"
fi