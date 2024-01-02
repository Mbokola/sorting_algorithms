#!/usr/bin/env python3
"""1-fifo_cache module
"""

from base_caching import BaseCaching


class LIFOCache(BaseCaching):
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
            tmp = {**self.cache_data}
            tmp[key] = item
            if len(tmp) > BaseCaching.MAX_ITEMS:
                if key in self.cache_data:
                    del self.cache_data[key]
                    self.cache_data[key] = item
                else:
                    print(f"DISCARD: {self.cache_data.popitem()[0]}")
                    self.cache_data[key] = item
            else:
                if key in self.cache_data:
                    del self.cache_data[key]
                self.cache_data[key] = item

    def get(self, key):
        """ Returns the value in self.cache_data linked to key
        """
        if not key or key not in self.cache_data:
            return None
        return self.cache_data[key]
