User's Guide
============

Launching GTG
--------------

Docker
~~~~~~

.. code-block:: shell

  wget https://raw.githubusercontent.com/MingChen0919/gtgdocker/master/launch_dev_env.sh
  sh launch_dev_env.sh

This script will launch a docker container running the GTG app and another container running
a Galaxy instance. Login to the Galaxy instance with username **admin** and password **admin**
so that you can install tools from tool shed.

After running this script, you should see the following directories in your current directory:

.. code-block:: shell

  gtg_dev_dir/
  ├── database
  ├── galaxy_tool_repository
  └── shed_tools

Drupal Site
~~~~~~~~~~~~

.. If you want to add the galaxy tool generator to an existing Drupal site....


Using Galaxy Tool Generator
---------------------------

Create Tool XML
~~~~~~~~~~~~~~~~~

GTG provides three ways to build a Galaxy XML file:

* From scratch: builds XML from scratch using GTG.
* Aurora Galaxy Tool: this option starts with an template file for developing an Aurora Galaxy Tool.
* Uploaded XML: starts with an uploaded XML.


.. image:: /_static/images//create-tool-xml.png

Select the appropriate method and click the **Save** button.


.. toctree::
   :maxdepth: 1
   :caption: Contents:

   scratch_guide
   other_guide
