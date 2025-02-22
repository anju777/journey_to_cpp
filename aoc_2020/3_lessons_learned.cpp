/**
 * A few valuable lessons learned from 3.cpp!
 *
 * 1. int has a finite ceiling. Long does NOT mean long! Technically, for most
 * 64-bit architectures, it does seem to be the case that long is 64 bytes.
 *
 * However, that is NOT the case for MY computer, and the C++ standard only
 * mandates that longs are 4 or ore bytes. ALWAYS USE LONG LONG!
 *
 *
 * 2.If you DON'T use references and you declare a new variable
 * (e.g. Class class = classes[i]), then a copy gets made and passed into
 * class! Modifying class does not change anything about the actual class!
 * Instead, do one of the followings:
 *      - classes[i].var = 10;
 *      - Class& class = classes[i]; class.var = 10;
 *      - Class* p_class = &classes[i]; p_class -> var = 10;
 *
 * BAD:
 *      - Class class = classes[i]; class.var = 10;
 *
 * Verified:
 * SkiCourse & ski_course:
 *      0xd4ddff6f0 <- address of ski_course reference (0xd4ddff6fc)
 * ski_course[i]:
 *      0xd4ddff6f0 <- address of ski_courses element (0xd4ddff6fc)
 * SkiCourse ski_course:
 *      0xd4ddff750 <- address of new ski_course variable (0xd4ddff75c)
 * SkiCourse* ski_course:
 *      0xd4ddff6f0 <- Ski course pointer (0xd4ddff6fc)
 */