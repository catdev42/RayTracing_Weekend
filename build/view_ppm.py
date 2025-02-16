# view_ppm_color.py
from PIL import Image

def rgb_to_ansi(r, g, b):
    # Convert RGB to ANSI color escape code
    return f"\033[38;2;{r};{g};{b}m"

def view_ppm(filename):
    # Load image
    img = Image.open(filename)
    
    # Calculate dimensions for terminal
    term_width = 80
    aspect = img.height/img.width
    term_height = int(term_width * aspect * 0.5)
    
    # Resize for terminal display
    img = img.resize((term_width, term_height))
    
    # Dense ASCII char for colored blocks
    block = "█"
    
    # Print image with colors
    for y in range(term_height):
        for x in range(term_width):
            # Get RGB values
            pixel = img.getpixel((x,y))
            if isinstance(pixel, tuple):
                r,g,b = pixel
            else:
                r = g = b = pixel
                
            # Print colored block
            print(f"{rgb_to_ansi(r,g,b)}{block}", end='')
        print("\033[0m")  # Reset color at end of line

if __name__ == "__main__":
    view_ppm("image.ppm")