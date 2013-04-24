<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="2.0">
    
    <xsl:template match="/">
        <html>
            <head>
                <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
                <link rel="stylesheet" href="style.css" />
                <title><xsl:value-of select="randonnee/introduction/nom"/></title>
            </head>
            
            <body>
                
                <img id="imgRando"><xsl:attribute name="src"><xsl:value-of select="randonnee/image/@src" /></xsl:attribute></img>
                
                <h1> <xsl:value-of select="randonnee/introduction/nom" /> </h1>
                
                <p><b>SITUATION : </b> <xsl:value-of select="randonnee/introduction/situation" /> </p>
                
                <p> <xsl:value-of select="randonnee/introduction/prelude" /> </p>
                
                <p> <xsl:value-of select="randonnee/introduction/description_generale" /> </p>
                
                <h2><xsl:value-of select="randonnee/partie[./@titre='DESCRIPTION']/@titre"/></h2>
                <table>
                    <xsl:for-each select="randonnee/partie[@titre='DESCRIPTION']/etape">
                    <tr>
                        <td>
                            <p><xsl:value-of select="./@id" /> - <xsl:value-of select="./@nom" /></p>
                            <xsl:variable name="duree"><xsl:value-of select="@duree_estime" /></xsl:variable>
                            <xsl:variable name="minute"><xsl:value-of select="$duree mod 60" /></xsl:variable>
                            <xsl:variable name="heure"><xsl:value-of select="floor($duree div 60)" /></xsl:variable>
                            <p>distance : <xsl:value-of select="./@distance_a_parcourir" />m - duree : <xsl:value-of select="$heure"/>h<xsl:value-of select="$minute"/></p>
                            <p><xsl:value-of select="./description_etape"/></p>
                        </td>
                        <td>
                            <img><xsl:attribute name="src"><xsl:value-of select="./@src" /></xsl:attribute></img>
                        </td>
                    </tr>
                    </xsl:for-each>
                </table>
                
                <h2><xsl:value-of select="randonnee/partie[./@titre='THEMATIQUE CULTURELLE']/@titre"/></h2>
                <p><xsl:value-of select="randonnee/partie[./@titre='THEMATIQUE CULTURELLE']/description_culturel" /></p>
                
                <table>
                    <tr>
                        <td id="col1">
                            <div class="fiche">
                                <p class="titreFiche">FICHE TECHNIQUE</p>
                                <p><b>Information : </b> <xsl:value-of select="randonnee/fichetechnique/infos" /> </p>
                                <p><b>Recommandations : </b> <xsl:value-of select="randonnee/fichetechnique/recommandations" /> </p>
                                <p><b>Difficulté : </b> <xsl:value-of select="randonnee/fichetechnique/difficulte" /> </p>
                                <p><b>Epoque conseillée : </b> <xsl:value-of select="randonnee/fichetechnique/epoque" /> </p>
                                <p><b>Dénivelé : </b> <xsl:value-of select="sum(/randonnee/partie[@titre = 'DESCRIPTION']/etape/@denivele)"/>m </p>
                                <p><b>Distance : </b> <xsl:value-of select="sum(/randonnee/partie[@titre = 'DESCRIPTION']/etape/@distance_a_parcourir)"/>m </p>
                                <p><b>Altitude de départ : </b> <xsl:value-of select="/randonnee/partie[@titre = 'DESCRIPTION']/etape[@id = '1']/@altitude"/>m </p>
                                
                                <xsl:variable name="alt">
                                    <xsl:for-each select="randonnee/partie[@titre='DESCRIPTION']/etape">
                                        <xsl:sort select="@id" order="descending" data-type="number" />
                                        <xsl:if test="position()=1"><xsl:value-of select="@altitude" /></xsl:if>
                                    </xsl:for-each>
                                </xsl:variable>
                                <p><b>Altitude d'arrivée : </b> <xsl:value-of select="$alt"/>m </p>
                                
                                <xsl:variable name="altmax">
                                    <xsl:for-each select="randonnee/partie[@titre='DESCRIPTION']/etape">
                                        <xsl:sort select="@altitude" order="ascending" data-type="number" />
                                        <xsl:if test="position()=1"><xsl:value-of select="@altitude" /></xsl:if>
                                    </xsl:for-each>
                                </xsl:variable>
                                <p><b>Altitude max : </b> <xsl:value-of select="$altmax"/>m </p>
                                
                                <xsl:variable name="dureeTotale"><xsl:value-of select="sum(/randonnee/partie[@titre = 'DESCRIPTION']/etape/@duree_estime)"/></xsl:variable>
                                <xsl:variable name="minuteTotale"><xsl:value-of select="$dureeTotale mod 60" /></xsl:variable>
                                <xsl:variable name="heureTotale"><xsl:value-of select="floor($dureeTotale div 60)" /></xsl:variable>
                                <p><b>Temps total : </b> <xsl:value-of select="$heureTotale"/>h<xsl:value-of select="$minuteTotale"/> </p>
                                
                                <p><b>Depart : </b> <xsl:value-of select="randonnee/fichetechnique/depart" /> </p>
                                <p><b>Arrivée : </b> <xsl:value-of select="randonnee/fichetechnique/arrivee" /> </p>
                            </div>
                        </td>
                        <td id="col2">
                        </td>
                        <td id="col3">
                            <div class="fiche">
                                <p class="titreFiche">FICHE D'INFORMATION</p>
                                <p><b>Carte nécessaire : </b><xsl:value-of select="randonnee/ficheinfo/carte" /></p>
                                <p><b>Carroyage : </b><xsl:value-of select="randonnee/ficheinfo/carroyage" /></p>
                                <p><b>Nom : </b><xsl:value-of select="randonnee/ficheinfo/nom" /></p>
                                <p><b>Accés routier : </b><xsl:value-of select="randonnee/ficheinfo/acces" /></p>
                                <p><b>Parking : </b><xsl:value-of select="randonnee/ficheinfo/parking" /></p>
                                
                                <xsl:variable name="dep"><xsl:value-of select="randonnee/fichetechnique/depart" /></xsl:variable>
                                <xsl:variable name="arr"><xsl:value-of select="randonnee/fichetechnique/arrivee" /></xsl:variable>
                                <xsl:choose>
                                    <xsl:when test="$dep=$arr"><p><b>Type de parcours : </b> Boucle</p></xsl:when>
                                    <xsl:otherwise><p><b>Type de parcours : </b>Itinéraire</p></xsl:otherwise>
                                </xsl:choose>                                
                                
                                <p><b>Type de chemin : </b><xsl:value-of select="randonnee/ficheinfo/typedechemin" /></p>
                                <p><b>Type de terrain : </b><xsl:value-of select="randonnee/ficheinfo/typedeterrain" /></p>
                                <p><b>Matériel : </b><xsl:value-of select="randonnee/ficheinfo/materiel" /></p>
                            </div>
                        </td>
                    </tr>
                </table>
                
            </body>
        </html>
    </xsl:template>
    
</xsl:stylesheet>
