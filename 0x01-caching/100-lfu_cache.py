#!/usr/bin/env python3
"""1-fifo_cache module
"""

from base_caching import BaseCaching
from typing import Dict


class LFUCache(BaseCaching):
    """ A caching sytsem
    """

    count: Dict = {}

    def __init__(self):
        """ initialize the class
        """
        super().__init__()

    def put(self, key, item):
        """ Assigns to the dictionary self.cache_data the item
        value for the key key """
        if key and item:
            self.cache_data[key] = item

            if len(self.cache_data) > BaseCaching.MAX_ITEMS:
                keys = list(self.count)
                values = list(self.count.values())
                key_to_del = keys[0]
                key_val = values[0]
                for k, v in zip(keys, values):
                    if v < key_val:
                        key_val = v
                        key_to_del = k
                del self.cache_data[key_to_del]
                print(f"DISCARD: {key_to_del}")
            if key in self.count:
                self.count[key] += 1
            else:
                for k in {**self.count}:
                    if k not in self.cache_data:
                        del self.count[k]
                self.count[key] = 1

    def get(self, key):
        """ Returns the value in self.cache_data linked to key
        """
        if not key or key not in self.cache_data:
            return None
        if key in self.count:
            self.count[key] += 1
        return self.cache_data[key]
