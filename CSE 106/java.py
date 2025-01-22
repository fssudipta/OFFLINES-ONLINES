import base64

def generate_key(seed, length):
    # Generate a repeating key using a PRNG
    key = []
    state = seed
    for _ in range(length):
        state = (state * 1103515245 + 12345) % (2**31)  # LCG example
        key.append(state % 256)  # Modulo to fit ASCII range or specific tweak
    return key

def undo_equinox(ciphertext, key):
    # Reverse the cyclic transformation
    plaintext = ""
    for i, char in enumerate(ciphertext):
        shift = key[i % len(key)]
        plaintext += chr((ord(char) - shift) % 256)  # Example tweak
    return plaintext

def undo_astra(transformed_text):
    # Reinterpret symbols (e.g., decode Base64 or custom substitution)
    return base64.b64decode(transformed_text).decode('utf-8')  # Example

# Ciphertext and seed
ciphertext = '_2A7$zZ3L:BEwzfjh*Bq~?V8vzv"2-/Q,au"W}5kuLjv@f)r\'r7rp_zqeiIv6JO#Azeyf'
seed = 145556

# Derive the key and decrypt
key = generate_key(seed, len(ciphertext))
intermediate_text = undo_equinox(ciphertext, key)
original_message = undo_astra(intermediate_text)

print("Decoded Message:", original_message)
