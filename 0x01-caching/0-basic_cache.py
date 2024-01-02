#!/usr/bin/env python3
""" 0-basic_cache module
"""
from base_caching import BaseCaching


class BasicCache(BaseCaching):
    """A Caching system
    """
    def __init__(self):
        """ Initialise the class
        """
        super().__init__()

    def put(self, key, item):
        """ Assigns to the dictionary self.cache_data the item
        value for the key key """
        if key and item:
            self.cache_data[key] = item

    def get(self, key):
        """ Returns the value in self.cache_data linked to key
        """
        if not key or key not in self.cache_data:
            return None
        return self.cache_data[key]
