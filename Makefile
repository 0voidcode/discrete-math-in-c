CC = gcc              # C compiler
CXX = g++             # C++ compiler
CFLAGS = -Wall        # Compiler flags to show all warnings
DIST_DIR = dist       # Directory to store compiled executables

# Get the first file from the 'program' variable
firstfile := $(word 1, $(program))
# Extract the file extension of the first file
ext := $(suffix $(firstfile))

run:
	@mkdir -p $(DIST_DIR)      # Create dist directory if not exists
ifeq ($(ext),.c)
	$(CC) $(program) -o $(DIST_DIR)/output_program $(CFLAGS)   # Compile C files
else ifeq ($(ext),.cpp)
	$(CXX) $(program) -o $(DIST_DIR)/output_program $(CFLAGS)  # Compile C++ files
else
	@echo "Unsupported file type, Use .c or .cpp"  # Show error for unsupported files
	exit 1
endif
	./$(DIST_DIR)/output_program    # Run the compiled program

clean:
	rm -rf $(DIST_DIR)   # Remove the dist directory and its contents
