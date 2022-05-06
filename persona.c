#include "persona.h"

static char nombresMasculinos [][TAM_NOMBRE]=
{
    {"Hugo 	   "},
    {"Martin   "},
    {"Lucas    "},
    {"Mateo    "},
    {"Leo      "},
    {"Daniel   "},
    {"Alejandro"},
    {"Pablo    "},
    {"Manuel   "},
    {"Alvaro   "},
    {"Adrian   "},
    {"David    "},
    {"Mario    "},
    {"Enzo     "},
    {"Diego    "},
    {"Marcos   "},
    {"Izan     "},
    {"Javier   "},
    {"Marco    "},
    {"Alex     "},
    {"Bruno    "},
    {"Oliver   "},
    {"Miguel   "},
    {"Thiago   "},
    {"Antonio  "},
    {"Marcelo  "},
    {"Carlos   "},
    {"Angel    "},
    {"Juan     "},
    {"Gonzalo  "},
    {"Gael     "},
    {"Sergio   "},
    {"Nicolas  "},
    {"Dylan    "},
    {"Gabriel  "},
    {"Jorge    "},
    {"Jose     "},
    {"Adam     "},
    {"Liam     "},
    {"Eric     "},
    {"Samuel   "},
    {"Dario    "},
    {"Hector   "},
    {"Luca     "},
    {"Iker     "},
    {"Amir     "},
    {"Rodrigo  "},
    {"Saul     "},
    {"Victor   "},
    {"Francisco"},
    {"Ivan     "},
    {"Jesus    "},
    {"Jaime    "},
    {"Aaron    "},
    {"Ruben    "},
    {"Ian      "},
    {"Guillermo"},
    {"Erik     "},
    {"Mohamed  "},
    {"Julen    "},
    {"Luis     "},
    {"Pau      "},
    {"Unai     "},
    {"Rafael   "},
    {"Joel     "},
    {"Alberto  "},
    {"Pedro    "},
    {"Raul     "},
    {"Aitor    "},
    {"Santiago "},
    {"Rayan    "},
    {"Pol      "},
    {"Nil      "},
    {"Noah     "},
    {"Jan      "},
    {"Asier    "},
    {"Fernando "},
    {"Alonso   "},
    {"Matias   "},
    {"Biel     "},
    {"Andres   "},
    {"Axel     "},
    {"Ismael   "},
    {"Marti    "},
    {"Arnau    "},
    {"Imran    "},
    {"Luka     "},
    {"Ignacio  "},
    {"Aleix    "},
    {"Alan     "},
    {"Elias    "},
    {"Omar     "},
    {"Isaac    "},
    {"Youssef  "},
    {"Jon      "},
    {"Teo      "},
    {"Mauro    "},
    {"Oscar    "},
    {"Cristian "},
    {"Leonardo "}
};

static char nombresFemeninos [][TAM_NOMBRE]=
{
    {"Lucia 	"},
    {"Sofia     "},
    {"Martina   "},
    {"Maria     "},
    {"Julia     "},
    {"Paula     "},
    {"Valeria   "},
    {"Emma      "},
    {"Daniela   "},
    {"Carla     "},
    {"Alba      "},
    {"Noa       "},
    {"Alma      "},
    {"Sara      "},
    {"Carmen    "},
    {"Vega      "},
    {"Lara      "},
    {"Mia       "},
    {"Valentina "},
    {"Olivia    "},
    {"Claudia   "},
    {"Jimena    "},
    {"Lola      "},
    {"Chloe     "},
    {"Aitana    "},
    {"Abril     "},
    {"Ana       "},
    {"Laia      "},
    {"Triana    "},
    {"Candela   "},
    {"Alejandra "},
    {"Elena     "},
    {"Vera      "},
    {"Manuela   "},
    {"Adriana   "},
    {"Ines      "},
    {"Marta     "},
    {"Carlota   "},
    {"Irene     "},
    {"Victoria  "},
    {"Blanca    "},
    {"Marina    "},
    {"Laura     "},
    {"Rocio     "},
    {"Alicia    "},
    {"Clara     "},
    {"Nora      "},
    {"Lia       "},
    {"Ariadna   "},
    {"Zoe       "},
    {"Amira     "},
    {"Gala      "},
    {"Celia     "},
    {"Leire     "},
    {"Eva       "},
    {"Angela    "},
    {"Andrea    "},
    {"Africa    "},
    {"Luna      "},
    {"Ainhoa    "},
    {"Ainara    "},
    {"India     "},
    {"Nerea     "},
    {"Ona       "},
    {"Elsa      "},
    {"Isabel    "},
    {"Leyre     "},
    {"Gabriela  "},
    {"Aina      "},
    {"Cayetana  "},
    {"Iria      "},
    {"Jana      "},
    {"Mar       "},
    {"Cloe      "},
    {"Lina      "},
    {"Julieta   "},
    {"Adara     "},
    {"Naia      "},
    {"Iris      "},
    {"Nour      "},
    {"Mara      "},
    {"Helena    "},
    {"Yasmin    "},
    {"Natalia   "},
    {"Arlet     "},
    {"Diana     "},
    {"Aroa      "},
    {"Amaia     "},
    {"Cristina  "},
    {"Nahia     "},
    {"Isabella  "},
    {"Malak     "},
    {"Elia      "},
    {"Carolina  "},
    {"Berta     "},
    {"Fatima    "},
    {"Nuria     "},
    {"Azahara   "},
    {"Macarena  "},
    {"Aurora    "}
};

static char apellidos[][TAM_APELLIDO]=
{
    {"Gonzalez      "},
    {"Rodriguez     "},
    {"Gomez         "},
    {"Fernandez     "},
    {"Lopez         "},
    {"Diaz          "},
    {"Martinez      "},
    {"Perez         "},
    {"Garcia        "},
    {"Sanchez       "},
    {"Romero        "},
    {"Sosa          "},
    {"Torres        "},
    {"Alvarez       "},
    {"Ruiz          "},
    {"Ramirez       "},
    {"Flores        "},
    {"Benitez       "},
    {"Acosta        "},
    {"Medina        "},
    {"Herrera       "},
    {"Suarez        "},
    {"Aguirre       "},
    {"Gimenez       "},
    {"Gutierrez     "},
    {"Pereyra       "},
    {"Rojas         "},
    {"Molina        "},
    {"Castro        "},
    {"Ortiz         "},
    {"Silva         "},
    {"Nuñez         "},
    {"Luna          "},
    {"Juarez        "},
    {"Cabrera       "},
    {"Rios          "},
    {"Morales       "},
    {"Godoy         "},
    {"Moreno        "},
    {"Ferreyra      "},
    {"Dominguez     "},
    {"Carrizo       "},
    {"Peralta       "},
    {"Castillo      "},
    {"Ledesma       "},
    {"Quiroga       "},
    {"Vega          "},
    {"Vera          "},
    {"Muñoz         "},
    {"Ojeda         "},
    {"Ponce         "},
    {"Villalba      "},
    {"Cardozo       "},
    {"Navarro       "},
    {"Coronel       "},
    {"Vazquez       "},
    {"Ramos         "},
    {"Vargas        "},
    {"Caceres       "},
    {"Arias         "},
    {"Figueroa      "},
    {"Cordoba       "},
    {"Correa        "},
    {"Maldonado     "},
    {"Paz           "},
    {"Rivero        "},
    {"Miranda       "},
    {"Mansilla      "},
    {"Farias        "},
    {"Roldan        "},
    {"Mendez        "},
    {"Guzman        "},
    {"Aguero        "},
    {"Hernandez     "},
    {"Lucero        "},
    {"Cruz          "},
    {"Paez          "},
    {"Escobar       "},
    {"Mendoza       "},
    {"Barrios       "},
    {"Bustos        "},
    {"Avila         "},
    {"Ayala         "},
    {"Blanco        "},
    {"Soria         "},
    {"Maidana       "},
    {"Acuña         "},
    {"Leiva         "},
    {"Duarte        "},
    {"Moyano        "},
    {"Campos        "},
    {"Soto          "},
    {"Martin        "},
    {"Valdez        "},
    {"Bravo         "},
    {"Chavez        "},
    {"Velazquez     "},
    {"Olivera       "},
    {"Toledo        "},
    {"Franco        "},
    {"Ibañez        "},
    {"Leguizamon    "},
    {"Montenegro    "},
    {"Delgado       "},
    {"Arce          "},
    {"Ibarra        "},
    {"Gallardo      "},
    {"Santillan     "},
    {"Acevedo       "},
    {"Aguilar       "},
    {"Vallejos      "},
    {"Contreras     "},
    {"Alegre        "},
    {"Galvan        "},
    {"Oviedo        "},
    {"Aranda        "},
    {"Albornoz      "},
    {"Baez          "},
    {"Sandoval      "},
    {"Barrionuevo   "},
    {"Veron         "},
    {"Gauna         "},
    {"Zarate        "},
    {"Heredia       "},
    {"Mercado       "},
    {"Monzon        "},
    {"Marquez       "},
    {"Zalazar       "},
    {"Mamani        "},
    {"Coria         "},
    {"Segovia       "},
    {"Romano        "},
    {"Jimenez       "},
    {"Salinas       "},
    {"Quinteros     "},
    {"Barrera       "},
    {"Ortega        "},
    {"Cabral        "},
    {"Palacios      "},
    {"Cejas         "},
    {"Quintana      "},
    {"Zapata        "},
    {"Rosales       "},
    {"Altamirano    "},
    {"Nieva         "},
    {"Bazan         "},
    {"Alonso        "},
    {"Burgos        "},
    {"Bustamante    "},
    {"Varela        "},
    {"Lescano       "},
    {"Aguilera      "},
    {"Paredes       "},
    {"Avalos        "},
    {"Cuello        "},
    {"Aquino        "},
    {"Orellana      "},
    {"Caballero     "},
    {"Reynoso       "},
    {"Reyes         "},
    {"Villarreal    "},
    {"Alarcon       "},
    {"Pacheco       "},
    {"Tapia         "},
    {"Galarza       "},
    {"Ocampo        "},
    {"Meza          "},
    {"Guerrero      "},
    {"Salas         "},
    {"Frias         "},
    {"Videla        "},
    {"Miño          "},
    {"Jara          "},
    {"Garay         "},
    {"Rossi         "},
    {"Lezcano       "},
    {"Valenzuela    "},
    {"Oliva         "},
    {"Fuentes       "},
    {"Robledo       "},
    {"Espindola     "},
    {"Nieto         "},
    {"Pereira       "},
    {"Brizuela      "},
    {"Andrada       "},
    {"Maciel        "},
    {"Funes         "},
    {"Robles        "},
    {"Sotelo        "},
    {"Cortez        "},
    {"Almiron       "},
    {"Rivas         "},
    {"Gil           "},
    {"Villegas      "},
    {"Calderon      "},
    {"Vergara       "},
    {"Carabajal     "},
    {"Ceballos      "},
    {"Gallo         "},
    {"Palavecino    "},
    {"Barreto       "},
    {"Alderete      "},
    {"Escudero      "},
    {"Saavedra      "},
    {"Serrano       "},
    {"Almada        "},
    {"Galeano       "},
    {"Espinosa      "},
    {"Villagra      "},
    {"Gerez         "},
    {"Solis         "},
    {"Ochoa         "},
    {"Escalante     "},
    {"Luque         "},
    {"Amaya         "},
    {"Arguello      "},
    {"Salazar       "},
    {"Lazarte       "},
    {"Barrientos    "},
    {"Vidal         "},
    {"Machado       "},
    {"Ferreira      "},
    {"Argañaraz     "},
    {"Iglesias      "},
    {"Guevara       "},
    {"Centurion     "},
    {"Esquivel      "},
    {"Lencina       "},
    {"Jaime         "},
    {"Cano          "},
    {"Lujan         "},
    {"Espinoza      "},
    {"Palacio       "},
    {"Villanueva    "},
    {"Salvatierra   "},
    {"Guerra        "},
    {"Barraza       "},
    {"Bordon        "},
    {"Saucedo       "},
    {"Ferrari       "},
    {"Costa         "},
    {"Rolon         "},
    {"Zabala        "},
    {"Albarracin    "},
    {"Duran         "},
    {"Peña          "},
    {"Tello         "},
    {"Quiroz        "},
    {"Montes        "},
    {"Alfonso       "},
    {"Brito         "},
    {"Marin         "},
    {"Moreira       "},
    {"Olmos         "},
    {"Montiel       "},
    {"Pintos        "},
    {"Olmedo        "},
    {"Bruno         "},
    {"Villafañe     "},
    {"Arroyo        "},
    {"Reinoso       "},
    {"Araujo        "},
    {"Gorosito      "},
    {"Cisneros      "},
    {"Quevedo       "},
    {"Montero       "},
    {"Barros        "},
    {"Moya          "},
    {"Basualdo      "},
    {"Carballo      "},
    {"Insaurralde   "},
    {"Prieto        "},
    {"Alcaraz       "},
    {"Santos        "},
    {"Corvalan      "},
    {"Chamorro      "},
    {"Casas         "},
    {"Carranza      "},
    {"Moreyra       "},
    {"Chaves        "},
    {"Riquelme      "},
    {"Arevalo       "},
    {"Bogado        "},
    {"Sequeira      "},
    {"Amarilla      "},
    {"Parra         "},
    {"Corbalan      "},
    {"Veliz         "},
    {"Falcon        "},
    {"Moran         "},
    {"Cantero       "},
    {"Otero         "},
    {"Rocha         "},
    {"Lobo          "},
    {"Cuevas        "},
    {"Roman         "},
    {"Caro          "},
    {"Jofre         "},
    {"Nievas 		"},
};

void crearLotePersonas (t_persona *per, size_t tamLote)
{
    int i,
        k,
        base,
        defineSexo; /// 0:Femenino 1: Masculino
    /// Porque per++ u no per+=sizeof(t_persona)
    /// porque estoy pasando un vector y no un puntero
    for ( i=0 ; i< tamLote; i++, per++)
    {
        defineSexo = rand() % 2 ;

        str_cpy(per->ape, apellidos[rand() % CANT_APE] );
        str_cat(per->ape, " " );

        if (defineSexo==0)
        {
            per->sexo=Femenino;
            str_cpy(per->nom, nombresFemeninos[rand() % CANT_NOM_FEME] );
            str_cat(per->nom, " " );
            str_cat(per->nom, nombresFemeninos[rand() % CANT_NOM_FEME] );
        }
        else
        {
            per->sexo=Masculino;
            str_cpy(per->nom, nombresMasculinos[rand() % CANT_NOM_MASC] );
            str_cat(per->nom, " " );
            str_cat(per->nom, nombresMasculinos[rand() % CANT_NOM_MASC] );
        }

        normalizar( per->ape);
        normalizar( per->nom);

        per->dni = 0;
        base=1;
        for (k=0 ; k<7; k++)
        {
            per->dni += (rand() % 10) * base;
            base*=10;
        }
        /// el digito mas significativo no puede ser cero para
        /// tener todos los dni de 8 digitos
        base*=10;
        per->dni += (rand() % 9 + 1) * base;
    }

}

void cargarLoteAlumnos (t_alumno *alum, t_persona *per, size_t ini, size_t tamLote)
{
    int i,
        j;

    alum+=ini;

    for ( i=ini ; i< tamLote; i++, alum++, per++)
    {
        /// Siempre que el orden de los tipos de datos de las 2 estructuras coincidan
        mem_cpy (alum, per, sizeof(t_persona));
        /*
        str_cpy(alum->ape, per->ape );
        alum->sexo=per->sexo;
        str_cpy(alum->nom, per->nom );
        alum->dni = per->dni;
        */

        alum->notas[TAM_NOTAS - 1] = 0;
        for (j=0; j< TAM_NOTAS - 1; j++)
        {
           alum->notas[j]= rand() % (11);
           alum->notas[TAM_NOTAS - 1] += alum->notas[j];
        }
       alum->notas[TAM_NOTAS - 1]/= TAM_NOTAS - 1 ;

       if (alum->notas[TAM_NOTAS - 1] >= 7)
            str_cpy(alum->mensaje, "Promociono");
       else
            str_cpy(alum->mensaje, " ");
    }
}

void cargarLoteEmpleados (t_empleado *emp,t_persona *per, size_t ini, size_t tamLote)
{
    int i;

    emp+=ini;

    for ( i=ini ; i< tamLote; i++, per++, emp++)
    {
        mem_cpy (emp, per, sizeof(t_persona));
        /*
        str_cpy(emp->ape, per[->ape );
        emp->sexo=per->sexo;
        str_cpy(emp->nom, per->nom );
        emp->dni = per->dni;
        */
        /// El rango de sueldo es de 5000 a 20000
        emp->sueldo = rand() % 20001 + 5000;
        str_cpy(emp->mensaje," ");
    }

}


void mostrarPersonas (t_persona *per, int pos)
{
       printf ("\nPersona %-5d->%*c"
               "Apellido:|%s|%*c"
               "Nombre:|%s|%*c"
               "DNI:|%d|%*c"
               "Sexo:|%c| \n"
               , pos,5,' '
               , per->ape,20 - str_len(per->ape), ' '
               , per->nom,20 - str_len(per->nom), ' '
               , per->dni,5,' '
               , per->sexo);
}

void mostrarAlumnos (t_alumno *alum, int pos)
{
    printf ("\nAlumno %-5d->%*c"
            "Apellido:|%s|%*c"
            "Nombre:|%s|%*c"
            "DNI:|%d|%*c"
            "Sexo:|%c|%*c"
            "Nota1%s|%.2f|%*c"
            "Nota2:%*c|%.2f|%*c"
            "Nota3:%*c|%.2f|%*c"
            "Promedio:%*c|%.2f|"
            "%*c%s\n"
            , pos,5,' '
            , alum->ape, 20 - str_len(alum->ape), ' '
            , alum->nom, 20 - str_len(alum->nom), ' '
            , alum->dni,5,' '
            , alum->sexo,5,' '
            , (alum->notas[nota_1] ==10 ? ":":": "),alum->notas[nota_1],5,' '
            , (alum->notas[nota_2] ==10 ? 1:2),' ',alum->notas[nota_2],5,' '
            , (alum->notas[nota_3] ==10 ? 1:2),' ',alum->notas[nota_3],5,' '
            , (alum->notas[promedio] ==10 ? 1:2),' ',alum->notas[promedio]
            ,10,' ',alum->mensaje);

}

void mostrarEmpleados (t_empleado *emp, int pos)
{
    printf ("\nEmpleado %-5d->%*c"
            "Apellido:|%s|%*c"
            "Nombre:|%s|%*c"
            "DNI:|%d|%*c"
            "Sexo:|%c|%*c"
            "Sueldo:|%.2f|%*c"
            "%*c%s\n"
            ,pos,5,' '
            ,emp->ape,20 - str_len(emp->ape), ' '
            ,emp->nom, 20 - str_len(emp->nom), ' '
            ,emp->dni,5,' '
            ,emp->sexo,5,' '
            ,emp->sueldo,5,' '
            ,10,' ',emp->mensaje);

}

int comparaPersonas (const void *d1, const  void *d2)
{

    int cmp;
    const t_persona *p1= d1,
                    *p2= d2;

    cmp = str_cmp(p1->ape, p2->ape);
    if ( cmp == 0)
    {
        cmp =str_cmp(p1->nom, p2->nom);
        if (cmp ==0)
            return p1->dni - p2->dni ;
    }
    return cmp;
}

void vaciarLotePersonas(t_persona *per, size_t tamLote)
{
    int i;

    for ( i=0 ; i< tamLote; i++, per++)
    {
        per->sexo = ' ' ;
        str_cpy(per->ape, " " );
        str_cpy(per->nom, " " );
        per->dni = 0;
    }
}
