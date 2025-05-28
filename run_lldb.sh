#!/bin/sh

set -eu
CONFIG_FILE="lldb_config_for_fulminate.lldb"
BIN="./main.exe"

lldb -S $CONFIG_FILE
