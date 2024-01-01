#!/usr/bin/env python3
""" 0-simple_helper_function module """
from typing import Tuple


def index_range(page: int, page_size: int) -> Tuple:
    return ((page * page_size) - page_size, page * page_size)