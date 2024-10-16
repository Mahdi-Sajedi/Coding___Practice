#!/usr/bin/env python3

import os

def get_path(filename):
  """play with it!"""
  head, tail = os.path.split(filename)
  return head

filename = __file__
import pdb; pdb.set_trace()

fpath = get_path(filename)
print(f"This is file's path: {fpath}")
