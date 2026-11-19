# Architecture
Phone recognizes speech → sends text → ESP32 CommandRouter → RecipeRunner / InventoryManager → CarouselController.
Recipe URL → external importer (Python) → human review → save structured recipe to ESP32.
