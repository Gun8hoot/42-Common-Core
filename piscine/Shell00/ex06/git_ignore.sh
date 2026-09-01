#!/bin/bash
git check-ignore -v -- * | awk '{print $2}'
