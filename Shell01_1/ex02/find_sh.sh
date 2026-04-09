#!/bin/bash
find . -name "*.sh" -type f | awk -F'/' '{print $NF}' | cut -d. -f1
