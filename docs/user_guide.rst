.. _UsersGuide:

User's Guide
============

Understanding the GTG workspace
--------------------------------------

After launching the GTG application, you should see the the folder ``gtg_dev_dir`` in your current directory and
three subdirectories within it:

.. code-block:: shell

  gtg_dev_dir/
  ├── database
  ├── galaxy_tool_repository
  └── shed_tools

The ``galaxy_tool_repository`` subdirectory stores all files that form a Galaxy Tool Repository and can be published to
Galaxy ToolShed with GTG. The subdirectory is mounted to the GTG container so that a developer can easily add non-XML
files from the host machine to the GTG container. The XML files should be generated via GTG.

The ``shed_tools`` subdirectory is mounted to both the GTG container and the Galaxy container so that the galaxy tool
repository being developed in GTG can be synced to the Galaxy instance for interactive testing.

The ``database`` subdirectory is mounted to the Galaxy container and displays the job working status of Galaxy. When the tool is being
tested in Galaxy, the job running process can be monitored. This is useful for debugging your tools.


Creating the Tool XML
-----------------------

GTG provides three ways to build a Galaxy XML file:

* **From scratch**: builds XML from scratch using GTG.
* **Uploaded XML**: starts with an uploaded XML.
* **Aurora Galaxy Tool**: this option starts with an template file for developing an Aurora Galaxy Tool.


.. image:: /_static/images//create-tool-xml.png

Select the appropriate method and click the **Save** button.


.. toctree::
   :maxdepth: 3
   :caption: Creating The XML:

   scratch_guide
   uploaded_xml_guide
   aurora_guide



Final Steps and Publishing
---------------------------


.. toctree::
  :maxdepth: 2
  :caption: Building Your Tool

  build_publish
