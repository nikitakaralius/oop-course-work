# Use an official C++ development image as a base
FROM danger89/cmake:latest

# Set the working directory in the container
WORKDIR /app

# Copy the CMakeLists.txt and the source code of the application to the working directory
COPY CMakeLists.txt /app
COPY /src /app/src

# Run CMake to create the build files
RUN cmake .

# Compile the source code
RUN make

ENTRYPOINT ["./FileWizard"]