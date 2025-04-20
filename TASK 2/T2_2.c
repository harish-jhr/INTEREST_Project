void T2_2()
{
    int binsX = 40;  
    int binsY = 40;  
    double minX = -40, maxX = 40;  // X-axis range (AngXZ in degrees)
    double minY = -40, maxY = 40;  // Y-axis range (AngYZ in degrees)
    
    TH2D *h2 = new TH2D("h2", "Muon Track Angles Distribution", 
                         binsX, minX, maxX, binsY, minY, maxY);
    fstream file;
    std::vector<double> Angles_XZ;
    std::vector<double> Angles_YZ;
    file.open("Angles_XZ.txt",ios::in);
    double angle;
    while(1)
    {
        file>>angle;
        Angles_XZ.push_back(angle);
        if(file.eof()) break;
    }
    file.close();
    file.open("Angles_YZ.txt",ios::in);
    while(1)
    {
        file>>angle;
        Angles_YZ.push_back(angle);
        if(file.eof()) break;
    }
    file.close();
    for (size_t i = 0; i < Angles_XZ.size(); ++i) {
        h2->Fill(Angles_XZ[i], Angles_YZ[i]);
    }

    h2->SetXTitle("AngXZ (deg)");
    h2->SetYTitle("AngYZ (deg)");
    h2->SetZTitle("Number of Events");
    // gStyle->SetPalette(kRainBow);

    // canvas
    TCanvas *c1 = new TCanvas("c1", "Muon Track Angles", 800, 600);
    h2->Draw("LEGO2Z"); 
}