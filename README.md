# NormaBase: Definitely not your go-to database

- ## What is NormaBase?
    NormaBase is a small, concise database, built for one purpose: learning the inner workings of databases.

    The initial goal is to bridge the gap between lower level intricacies and high level functionality. By looking into what happens behind the scenes, the understanding of such technologies is deepened and refined.

    Thus the system design skills, the most important in software engineering, become better.

    The potential goal however, is to create a real, functional database to help store and manipulate data for ML and AI models.

- ## How was NormaBase built?
    NormaBase is built using C.\
    Why not Rust? Or C++?
    
    There wasn't any need for OOP features from C++, you'll eventually strip down C++ until you're working with what C already provides.\

    And Rust was avoided for the very problem it solves, memory management. To learn systems better, and to appreciate such features, you must go through a dozen segmentation faults first.

- ## Limitations:
    This is *STILL* a learning project, don't expect it to work at scale, or be used in real projects *yet*