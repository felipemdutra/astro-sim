# Compiler settings
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17 -I./src
LDFLAGS := 
LDLIBS := -lglfw -lGL -lGLEW

# Project structure
SRCDIR := src
BUILDDIR := build
TARGET := astro-sim

# Automatically discover source files
SRCS := $(shell find $(SRCDIR) -name '*.cpp')
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Default target
all: $(BUILDDIR) $(TARGET)

# Create build directory
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# Compile with dependency generation
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# Include auto-generated dependencies
-include $(DEPS)

# Clean
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Run (optional)
run: all
	./$(TARGET)

# Phony targets
.PHONY: all clean run
