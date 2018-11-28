Quick Start Guide
=================

.. note::

  Please see our detailed :ref:`usersGuide` for detailed instructions on using GTG.


* Open the GTG web interface.
* Use the **Create Tool XML** tab to start your XML file.
* Add XML components and set their attributes. 
* Press the **Update XMLs in galaxy_tool_directory folder** button in the **Build Tool Repository** tab to add the finished XML to the repository.
* Add any additional files to the ``gtg_dev_dir/galaxy_tool_repository`` folder.
* Connect GTG to the Galaxy Toolshed in the **Connect to ToolShed** tab.
* Publish to the Test Toolshed in the **Publish Tool Repository** tab.
* Install and test your published tool in the local Galaxy container using the **Sync to Galaxy** field in the **Build Tool Repository** tab, providing the path relative to the ``shed_tools`` directory.
* Restart Galaxy to integrate the changes:  ``docker exec -it gtg_galaxy sh -c 'supervisorctl restart galaxy:'``
