Quick Start Guide
=================

Requirements
------------


GTG depends on two Docker images: ``statonlab/galaxy_tool_generator`` and ``bgruening/galaxy-stable:17.09``. First, you need
to `install Docker <https://docs.docker.com/install/>`_ in your system. Then, run the following command to get the two images.

.. code-block:: shell

    docker pull statonlab/galaxy_tool_generator
    docker pull bgruening/galaxy-stable:17.09


Launch GTG with Docker
-----------------------

Run the code below to launch GTG. This will start a GTG application at http://127.0.0.1:8089/ and a Galaxy instance at
http://127.0.0.1:8090/.

.. code-block:: shell

    git clone https://github.com/statonlab/galaxy_tool_generator.git
    cd galaxy_tool_generator && docker-compose up -d

To shut down GTG and the Galaxy containers:

.. code-block:: shell

    docker-compose down


If you want to run GTG and the Galaxy containers at different ports, you can edit the port numbers in the `docker-compose.yml`
file.

.. image:: /_static/images/docker-compose-yml.png

Building Your Tool
----------------------

Please see the user guide for detailed instructions on using GTG.
