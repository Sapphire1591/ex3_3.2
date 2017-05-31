#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "escapeTechnion.h"
#include "mtm_ex3.h"

#define FACULTY_NUM 18

struct SFaculty {
    TechnionFaculty Name; //Faculty name - from enum list
    List* CompanyList; //pointer?
    int total_revenue; //total income from escapers
};

static MtmErrorCode createFacultyArray() {
    Faculty FacultyList[FACULTY_NUM];
    for (int i=0; i<FACULTY_NUM; i++) {
        FacultyList[i] = malloc(sizeof(Faculty));
        if (FacultyList[i] == NULL) {
            return MTM_OUT_OF_MEMORY;
        }
        FacultyList[i]->total_revenue = 0;
        //FacultyList[i]->CompanyList = createCompanyList(copy, delete); //when created
    }
    FacultyList[CIVIL_ENGINEERING]->Name = CIVIL_ENGINEERING;
    FacultyList[MECHANICAL_ENGINEERING]->Name = MECHANICAL_ENGINEERING;
    FacultyList[ELECTRICAL_ENGINEERING]->Name = ELECTRICAL_ENGINEERING;
    FacultyList[CHEMICAL_ENGINEERING]->Name = CHEMICAL_ENGINEERING;
    FacultyList[BIOTECHNOLOGY_AND_FOOD_ENGINEERING]->Name =
                BIOTECHNOLOGY_AND_FOOD_ENGINEERING;
    FacultyList[AEROSPACE_ENGINEERING]->Name = AEROSPACE_ENGINEERING;
    FacultyList[INDUSTRIAL_ENGINEERING_AND_MANAGEMENT]->Name =
                INDUSTRIAL_ENGINEERING_AND_MANAGEMENT;
    FacultyList[MATHEMATICS]->Name = MATHEMATICS;
    FacultyList[PHYSICS]->Name = PHYSICS;
    FacultyList[CHEMISTRY]->Name = CHEMISTRY;
    FacultyList[BIOLOGY]->Name = BIOLOGY;
    FacultyList[ARCHITECTURE]->Name = ARCHITECTURE;
    FacultyList[EDUCATION_IN_TECH_AND_SCIENCE]->Name =
                EDUCATION_IN_TECH_AND_SCIENCE;
    FacultyList[COMPUTER_SCIENCE]->Name = COMPUTER_SCIENCE;
    FacultyList[MEDICINE]->Name = MEDICINE;
    FacultyList[MATERIALS_ENGINEERING]->Name = MATERIALS_ENGINEERING;
    FacultyList[HUMANITIES_AND_ARTS]->Name = HUMANITIES_AND_ARTS;
    FacultyList[BIOMEDICAL_ENGINEERING]->Name = BIOMEDICAL_ENGINEERING;

    return MTM_SUCCESS;
}
