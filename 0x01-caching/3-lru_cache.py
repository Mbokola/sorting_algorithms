#!/usr/bin/env python3
"""1-fifo_cache module
"""

from base_caching import BaseCaching


class LRUCache(BaseCaching):
    """ A caching sytsem
    """
    def __init__(self):
        """ initialize the class
        """
        super().__init__()

    def put(self, key, item):
        """ Assigns to the dictionary self.cache_data the item
        value for the key key """
        if key and item:
            if key in self.cache_data:
                del (self.cache_data[key])
                self.cache_data[key] = item
                return self.cache_data
            self.cache_data[key] = item
            if len(self.cache_data) > BaseCaching.MAX_ITEMS:
                key = list(self.cache_data.keys())[0]
                del (self.cache_data[key])
                print(f"DISCARD: {key}")

    def get(self, key):
        """ Returns the value in self.cache_data linked to key
        """
        if not key or key not in self.cache_data:
            return None
        item = self.cache_data[key]
        del (self.cache_data[key])
        self.cache_data[key] = item
        return self.cache_data[key]
