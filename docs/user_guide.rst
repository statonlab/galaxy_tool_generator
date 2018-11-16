User's Guide
============

Workspace: gtg_dev_dir
----------------------

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


Create Tool XML
---------------

GTG provides three ways to build a Galaxy XML file:

* **From scratch**: builds XML from scratch using GTG.
* **Uploaded XML**: starts with an uploaded XML.
* **Aurora Galaxy Tool**: this option starts with an template file for developing an Aurora Galaxy Tool.


.. image:: /_static/images//create-tool-xml.png

Select the appropriate method and click the **Save** button.


.. toctree::
   :maxdepth: 3
   :caption: Contents:

   scratch_guide
   aurora_guide
   uploaded_xml_guide



Build Tool Repository
----------------------------

Add XML files to ``galaxy_tool_repository``
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


You have just created the ``seqtk_seq_2.xml`` file in GTG. However, this file is not in the ``gtg_dev_dir/galaxy_tool_repository`` directory yet.
We need to copy the XML file into it, and any other non-XML files if there are any.

Click the **Build Tool Repository** tab and select any XML files that you want to add to the ``gtg_dev_dir/galaxy_tool_repository`` directory. And then click the **Update XMLs in galaxy_tool_directory folder** button.

.. note::

  This is also the button that you use to add an updated XML to the directory.

.. image:: /_static/images/build_tool_repository.png

You should be able to see the ``seqtk_seq_2.xml`` file in the ``gtg_dev_dir/galaxy_tool_repository`` directory.

.. image:: /_static/images/gtg_dev_dir.png



Add non-XML files to ``galaxy_tool_repository``
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


If this tool requires any other non-XML files (for example, test files, scripts, etc.), you can add them directly to
the ``gtg_dev_dir/galaxy_tool_repository`` directory.



Connect to ToolShed
-------------------

Once we have the XML file(s) and all other non-XML files in the ``gtg_dev_dir/galaxy_tool_repository``, we can publish
the tool to Test ToolShed or ToolShed with GTG. We need to connect to the Galaxy ToolShed or Test ToolShed to publish
Galaxy tools. This can be down by adding the API keys through the following interface. Visit the Toolshed documentation
to learn more about API keys:  https://docs.galaxyproject.org/en/release_18.05/api/ts_api.html


.. image:: /_static/images/api_key.png



Publish to Tool Repository
--------------------------

After we have connected with a ToolShed platform, we can publish the tool through the interface below.

.. image:: /_static/images/publish_tool.png


Install and test Tool in Galaxy
-------------------------------

The next step would be to install and test the tool in the connected Galaxy instance. If the tool needs more work, you can use GTG to update the XML file.

The **Sync to Galaxy** field on the **Build Tool Repository** page is used to link the tool in GTG with the same tool installed in Galaxy so that the update will be automatically synced to Galaxy for testing.

.. image:: /_static/images/sync_tool.png

Every time you update the XML file in Galaxy, you will need to restart Galaxy to integrate the updates. Below is the command to restart Galaxy.

.. code-block:: shell

  docker exec -it gtg_galaxy sh -c 'supervisorctl restart galaxy:'

You should see the following stdout.

.. code-block:: shell

  galaxy:galaxy_nodejs_proxy: stopped
  galaxy:handler0: stopped
  galaxy:handler1: stopped
  galaxy:galaxy_web: stopped
  galaxy:galaxy_nodejs_proxy: started
  galaxy:galaxy_web: started
  galaxy:handler0: started
  galaxy:handler1: started
