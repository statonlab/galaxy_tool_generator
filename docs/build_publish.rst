
Building the Finished Galaxy Tool
===================================

Now that the XML file is ready, there are some final steps for making the tool available on Galaxy ToolShed.


Add Files
----------


Add XML files to the ``galaxy_tool_repository`` directory
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


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
