import { Injectable } from '@nestjs/common';
import { PrismaService } from 'src/prisma/prisma.service';
import { CreateCategoryDto } from './dto/create-category.dto';
import { UpdateCategoryDto } from './dto/update-category.dto';

@Injectable()
export class CategoriesService {
  constructor(private prismaService: PrismaService) {}
  create(createCategoryDto: CreateCategoryDto) {
    return this.prismaService.category.create({
      data: createCategoryDto,
    });
  }

  async findAll() {
    const categories = await this.prismaService.category.findMany({
      select: {
        id: true,
        name: true,
      },
    });
    return categories;
  }

  findOne(id: string) {
    return this.prismaService.category.findFirst({
      where: {
        id: id,
      },
    });
  }

  update(id: string, updateCategoryDto: UpdateCategoryDto) {
    return this.prismaService.category.update({
      data: updateCategoryDto,
      where: { id: id },
    });
  }

  remove(id: string) {
    return this.prismaService.category.delete({
      where: {
        id,
      },
    });
  }
}
