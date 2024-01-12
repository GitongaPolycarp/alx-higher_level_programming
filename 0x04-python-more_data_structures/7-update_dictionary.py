#!/usr/bin/python3
def update_dictionary(a_dictionary, key, value):
    """Updates a dictionary by replacing or adding key/value pairs.

    Args:
        a_dictionary: The dictionary to update.
        key: The key to update or create.
        value: The new value to assign to the key.

    Returns:
        The updated dictionary.
    """

    a_dictionary[key] = value
    return (a_dictionary)
