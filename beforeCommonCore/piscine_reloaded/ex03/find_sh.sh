#!/bin/bash
find . -name "*.sh" | awk -F'/' '{print $NF}' | cut -d. -f1
